// Author: dknowles2@gmail.com (David Knowles)

import java.util.*;

public class IteratorDemo {
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
        Iterator i = v.iterator();
        while (i.hasNext()) {
            System.out.print(i.next() + " ");
        }
        System.out.println();
    }
}
