# creating simulator and object as ns
set ns [new Simulator]

# open a .tr file and make file object as tf
set tf [open labset1.tr w]
$ns trace-all $tf

# create nf as .nam file object
set nf [open labset1.nam w]
$ns namtrace-all $nf

# create a procedure/function as of finish
proc finish {} {
	global ns tf nf 
	$ns flush-trace
	close $tf
	close $nf
	exec nam labset1.nam &
	exec awk -f labset1.awk labset1.tr &
	exit 0
}

#create nodes of type Simulator node
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

# label the nodes 
$n0 label "TCP Source"
$n2 label "TCP Sink"

# create duplex link between nodes and also Bandwidth
$ns duplex-link $n0 $n1 100Mb 1ms DropTail
$ns duplex-link $n1 $n2 40Mb 2ms DropTail

$ns queue-limit $n1 $n2 5

# Attaching the agent to nodes 
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp


set ftp [new Application/FTP]
$ftp attach-agent $tcp 

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n2 $tcpsink 

$ns connect $tcp $tcpsink 
$ns at 0.2 "$ftp start"
$ns at 2.5 "$ftp stop"
$ns at 3.0 "finish"

$ns run


