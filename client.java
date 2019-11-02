import java.lang.*;
import java.io.*;
import java.net.*;

class Client {
   public static void main(String args[]) {
      try {
         Socket skt = new Socket("172.27.27.170", 5432);
         BufferedReader in = new BufferedReader(new
            InputStreamReader(skt.getInputStream()));
         System.out.print("Received string: '");

         // while (!in.ready()) {} line removed
         System.out.println(in.readLine());  


         System.out.print("'\n");
         // in.close();
         while(true);
      }
      /* lines removed catch(Exception e) {
         System.out.print("Whoops! It didn't work!\n");
      } */

      // added exception handling
      catch(UnknownHostException e) {
         e.printStackTrace();
      }
      catch (IOException e){
         e.printStackTrace();
      }

   }
}