// Author: dknowles2@gmail.com (David Knowles)

import java.util.*;

public class EnumerationDemo {
    public static void main(String args[]) {
        Vector v = new Vector();
        v.add("Fry");
        v.add("Leela");
        v.add("Bender");
        v.add("Hermes");
        v.add("Zoidberg");
        v.add("Farnsworth");
        v.add("Nibbler");
        v.add("Amy");

        System.out.print("Contents of v: ");
        Enumeration e = v.elements();
        while (e.hasMoreElements()) {
            System.out.print(e.nextElement() + " ");
        }
        System.out.println();
    }
}
