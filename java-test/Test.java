import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Test {
    public static void main(String[] args) {
        try {
            Process comm = new ProcessBuilder("./test.out").start();
            BufferedReader reader = 
                new BufferedReader(new InputStreamReader(comm.getInputStream()));
            String randLine = reader.readLine();
            switch(Integer.parseInt(randLine)) {
                case 0: System.out.println("0"); break;
                case 1: System.out.println("1"); break;
                case 2: System.out.println("2"); break;
                case 3: System.out.println("3"); break;
                case 4: System.out.println("4"); break;
                default: System.out.println("Whoops, this is embarassing"); break;
            }
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}