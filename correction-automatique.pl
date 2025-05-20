#!/usr/bin/perl
use strict;

main();

sub main {
    print "Correction automatique des TP (ZZ1-SDD-S2) - version etudiants\n";
    while (my $directory=<*>) {
        if ((-d $directory) and ($directory!~/^tmp/)) {
            correctionOfDirectory($directory);
        }
    }
}

sub correctionOfDirectory {
    my ($directory) = @_;
    if (not -d "$directory/tests/") {
        print "[ERROR] le repertoire '$directory/tests' est manquant\n";
        die;
    }
    if (not -f "$directory/tests/Makefile") {
        print "[ERROR] le fichier '$directory/tests/Makefile' est manquant\n";
        die;
    }
    chdir($directory);
    correction($directory);
    chdir("..");
}

sub correction {
    my ($directory) = @_;
    my @testScores;
    my @testNames;
    while (my $test=<tests/*.c>) {
        my $name = $test;
        $name=~s/^.*\///g;
        push(@testNames, $name);
        my $score = runTest($directory, $name);
        push(@testScores, $score);
    }
    printResults($directory, @testScores);
}

sub runTest {
    my ($directory, $name) = @_;
    system("mkdir tmp");
    system("cp *.c *.h tmp");
    system("cp tests/$name tmp/main.c");
    system("cp tests/Makefile tmp");
    chdir("tmp");
    system("make clean 1> /dev/null 2> /dev/null");
    my $compilationReturn = system("make 1> /dev/null 2> /dev/null");
    my $runReturn = system("timeout -k 5s 4s ./main 1> /dev/null 2> /dev/null");
    my $result = "x";
    if ($compilationReturn==0) {
        if ($runReturn==0) {
            $result = "1";
        }
        else {
            $result = "0";
        }
    }
    chdir("..");
    system("rm -rf tmp");
    return $result;
}

sub printResults {
    my ($directory, @testScores) = @_;
    print "$directory : bons=".getNumberOk(@testScores)." mauvais=".getNumberKo(@testScores)." problemes=".getNumberUncompile(@testScores)." => note (indicative)=".getNote(@testScores)."/20\n";
}

sub getNote {
    my (@testScores) = @_;
    my $numerator = getNumberOk(@testScores);
    my $denominator = $numerator+getNumberKo(@testScores)+getNumberUncompile(@testScores);
    if ($denominator==0) {
        return "?";
    }
    else {
        return 20*$numerator/$denominator;
    }
}

sub getNumberOk {
    my (@testScores) = @_;
    return getValue(\@testScores, "1");
}

sub getNumberKo {
    my (@testScores) = @_;
    return getValue(\@testScores, "0");
}

sub getNumberUncompile {
    my (@testScores) = @_;
    return getValue(\@testScores, "x");
}

sub getValue {
    my ($testScores, $value) = @_;
    my $number = 0;
    foreach my $v (@$testScores) {
        if ($v eq $value) {
            $number = $number+1;
        }
    }
    return $number;
}
