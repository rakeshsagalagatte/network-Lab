import java.io.*;
import java.net.*;
import java.util.*;

class Client{
    public static void main(String[] args){
      try{
               Scanner sc = new Scanner(System.in);
	       Socket socket = new Socket("localhost", 3000);
	       System.out.println("Enter the filename : ");
	       String fname = sc.nextLine();
	       OutputStream os = socket.getOutputStream();
	       PrintWriter pw = new PrintWriter(os , true);
	       pw.println(fname);
	       InputStream istream = socket.getInputStream();
	       BufferedReader br = new BufferedReader( new InputStreamReader(istream));
	       String st = "";
	       while((st = br.readLine())!= null){
		System.out.println(st);
	       } 
	       istream.close();
	       os.close();
	       socket.close();
      } catch(Exception e){}
 }
}
