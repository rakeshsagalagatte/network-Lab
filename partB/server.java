import java.io.*;
import java.net.*;

class Server{
     public static void main(String [] args){
           try{
                    ServerSocket ss = new ServerSocket(3000);
                    System.out.println("System ready for connection.!");
                    Socket socket = ss.accept();
      		    System.out.println("Connection established");

                    InputStream istream = socket.getInputStream();
 		    BufferedReader br = new BufferedReader(new InputStreamReader(istream));
        
                    String fname = br.readLine();
	            System.out.println("File name is " + fname);
		    BufferedReader brFile = new BufferedReader(new FileReader(fname));
		    OutputStream os = socket.getOutputStream();
		    PrintWriter pw = new PrintWriter(os, true);
		    String st = "";
		    while(( st = brFile.readLine())!= null){
                        pw.println(st);
                    }
		    istream.close();
		    os.close();
		    socket.close();
		    ss.close();
		    System.out.println("Connection terminated..!");
              }
		catch(Exception e){}
     }
}
