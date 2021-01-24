# creating simulator and object as ns
set ns [new Simulator]

# create a trace file , this file is for logging purpose
set tf [open udptcplabset.tr w]
$ns trace-all $tf

# create nf as .nam file object: animation information 
set nf [open udptcplabset.nam w]
$ns namtrace-all $nf

# create a procedure/function as of finish at 3 seconds 
proc finish {} {
	global ns tf nf 
	$ns flush-trace
	close $tf
	close $nf
	exec nam udptcplabset.nam &
	exec awk -f labset1.awk udptcplabset.tr &
	exit 0
}

#create nodes of type Simulator node
set s1 [$ns node]
set s2 [$ns node]
set r1 [$ns node]
set r2 [$ns node]
set s3 [$ns node]
set s4 [$ns node]

# label the nodes 
$s1 label "TCP Source"
$s4 label "TCP Sink"
$s2 label "UDP Source"
$s3 label "NULL"
$r1 label "r1"
$r2 label "r2"

# create duplex link between nodes and also Bandwidth
$ns duplex-link $s1 $r2 10Mb 2ms DropTail
$ns duplex-link $s2 $r1 5Mb 5ms DropTail
$ns duplex-link $r1 $r2 5Mb 10ms DropTail
$ns duplex-link $s3 $r2 50Mb 2ms DropTail
$ns duplex-link $s4 $r1 4Mb 10ms DropTail

#ns queue-limit $r1 $r2 5

# Attaching the agent to nodes 
set tcp [new Agent/TCP]
$ns attach-agent $s1 $tcp

set udp [new Agent/UDP]
$ns attach-agent $s2 $udp

set null [new Agent/Null]
$ns attach-agent $s3 $null

set tcpsink [new Agent/TCPSink]
$ns attach-agent $s4 $tcpsink

$ns connect $tcp $tcpsink
$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp 

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 0.2 "$cbr start"
$ns at 0.3 "$ftp start"
$ns at 3.0 "finish"

$ns run


