import java.util.*;
import java.io.*;

public class Framesort{
    public static void main(String [] arg){
        HashMap<Integer, String> frame = new HashMap<Integer , String>();
        ArrayList<Integer> index = new ArrayList<Integer>();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the message : ");
        String msg = scan.nextLine();
        System.out.print("Enter the number of network : ");
        int min=999,nw = scan.nextInt();
        for(int i=0; i < nw; i++){
            System.out.print("Enter the MTU : ");
            int mtu = scan.nextInt();
            if(mtu < min){
                min = mtu;
            }
            mtu = min;
            for(int m = 0,j=0 ;m < msg.length(); m = m+mtu,j++){
                String fra = "";
                if(m+mtu <= msg.length()){
                    fra = msg.substring(m,m+mtu);
                }else
                    fra = msg.substring(m,msg.length());
                frame.put(j,fra);
                System.out.println(j + " "+ fra);
                if(! index.contains(j)){
                    index.add(j);
                }
            }
            Collections.shuffle(index);
            System.out.println("After shuffling ");
            for(int j=0;j < index.size(); j++){
                System.out.println(index.get(j) + ":" + frame.get(index.get(j)));
            }
            System.out.println("After sorting ");
            Collections.sort(index);
            for(int j=0;j < index.size(); j++){
                System.out.println(index.get(j) + ":" + frame.get(index.get(j)));
            }
        }
    }
}