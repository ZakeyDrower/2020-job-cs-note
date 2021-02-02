import java.lang.reflect.Array;
import java.util.*;
import java.lang.*;
public class Main {

    public static String process(String str, char c) {
        String s = "";
        for(int i = 0; i < str.length(); ++i) {
            if(str[i] < c)
                s += str[i];
        }
        return s;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        List<String> list = new ArrayList<String>();
        char basechar;
        while(1) {
            String s = sc.nextLine();
            if(s.length() == 1) {
                basechar = s[0];
                break;
            }
            list.add(s);
        }

        String basestr = sc.nextLine();
        String baseline = prcess(basestr, basechar);
        for(int i = 0; i < list.size(); ++ i) {
            if(baseline.equals(process(list[i], basechar)))
                System.out.println(list[i]);
        }

        return 0;
    }
}

/**

135682318
23457
14282123
14231728
3
1724153


 */