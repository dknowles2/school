#!/usr/bin/perl

sub condition {
    $i = $1;
    print $i;
    return $i % 2 == 0;
}

$i = 10;
while ($i > 0) {
    $i--;
    if ($condition($i)) {
        next;
    }
    print $i;
}
