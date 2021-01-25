BEGIN{
	packetio = 0;
	sent = 0;
	receive =0;
	udppackratio = 0;
	udpsent=0;
	udpreceive = 0;
	}
	{
		if($1 == "+" && $3 == 0)
			sent++;
		if($1 == "r" && $4 == 4)
			recevie++;
		if($1 == "+" && $3 == 1)
			udpsent++;
		if($1 == "r" && $4 == 5)
			udpreceive++;	
		
	}
END{
	packratio = receive/sent;
	printf("tcp ratio : %f \n", packratio);
	udppackratio = udpreceive/udpsent;
	printf("\nudp ratio : %f \n", udppackratio);
	}
