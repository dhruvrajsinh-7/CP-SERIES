
import java.util.Scanner;
public class IntegerToRoman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number");
        int num = sc.nextInt();
        intToRoman(num);
    }
    public String intToRoman(int num){
        TreeMap<Integer,String>map = new TreeMap<>();
        map.put(1,"I");
        map.put(4,"IV");  
        map.put(5,"V");    
        map.put(9,"IX");     
        map.put(10,"X");     
        map.put(40,"XL");  
        map.put(50,"L");
        map.put(90,"XC");
        map.put(100,"C");
        map.put(400,"CD");
        map.put(500,"D");
        map.put(900,"CM");
        map.put(1000,"M");
        String resultedstring="";
        while(num>0){
            Integer nearestKey = map.floorKey(num);
            resultedstring =resultedstring + map.get(nearestKey);
            num = num - nearestKey;
        }
        return resultedstring;
 }
        
}
 