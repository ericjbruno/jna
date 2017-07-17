package jnatest;

import com.sun.jna.Callback;
import com.sun.jna.Library; 
import com.sun.jna.Native; 
import com.sun.jna.Platform;

public class JNATest {
    public interface CLibrary extends Library {
        CLibrary INSTANCE = (CLibrary)
            Native.loadLibrary((Platform.isWindows() ? "msvcrt" : "c"),
                               CLibrary.class);

        void printf(String format, Object... args);
    }

    //////////////////////

    public static class MyCLib {
        interface callback extends Callback {
            void invoke(int val);
        }
        
        public static native int calc(int x);
        public static native int log(String s);
        public static native String getname();
        public static native void callme(callback func);
        
        static {
            Native.register("MyCLib");
        }
    }
    
    static int value = 0;
    
    static MyCLib.callback func = new MyCLib.callback() {
        public void invoke(int val) {
            JNATest.value = val;
//            System.out.println("Value " + val + " was returned");
        }
    };    
    
    //////////////////////
    
    static JNATest INSTANCE = new JNATest();

    public JNATest() {
        System.out.println("*** JNATest() constructor ****");
    }
    
    public static void main(String[] args) {
        CLibrary.INSTANCE.printf("Starting...\n");

        MyCLib.log("Hello, " + MyCLib.getname() );
        
        MyCLib.log("The result of calc(2) = " + MyCLib.calc(2) );
        
        MyCLib.callme(func);
        
        MyCLib.log("The value from the callback was " + value);
    }   
}
