

set ns [new Simulator]

set tf [open bus_topology.tr w]
$ns trace-all $tf

set nf [open bus_topology.nam w]
$ns namtrace-all $nf 

proc finish {} {

	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam bus_topology.nam &
	exec awk -f labset1.awk bus_topology.tr &
	exit 0 
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd Channel]

set tcp [new Agent/TCP]


$ns attach-agent $n1 $tcp

$tcp set class_ 1
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

$ns connect $tcp $sink

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.01
$cbr attach-agent $tcp

$ns at 0.5 "$cbr start"
$ns at 4.5 "$cbr stop"

$ns at 5.0 "finish"

$ns run
