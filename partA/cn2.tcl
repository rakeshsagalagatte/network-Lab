set ns [new Simulator]
set tf [open out.tr w]
$ns trace all $tf

set nf [open cn.nam w]
$ns namtrace-all $nf

proc finish {} {
	global ns tf nf
	$ns flush-trace 
	close $tf
	close $nf
	exec nam cn.nam &
	#exec awk -f cn.awk cn.tr &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$n0 label "TCP Source"
$n3 label "TCP Sink"

$ns duplex-link $n0 $n1 90Mb 1ns DropTail
$ns duplex-link $n1 $n2 10Mb 2ns DropTail
$ns duplex-link $n2 $n3 1.5Mb 20ns DropTail
$ns queue-limit $n1 $n2 50
$ns queue-limit $n2 $n3 50


set tcp 
