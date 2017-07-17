package jnatest;

import com.sun.jna.Library; 
import com.sun.jna.Native; 
import com.sun.jna.Platform;

public class SimpleTest {
    public interface CLibrary extends Library {
        CLibrary INSTANCE = (CLibrary)
            Native.loadLibrary((Platform.isWindows() ? "msvcrt" : "c"),
                               CLibrary.class);

        void printf(String format, Object... args);
    }
    
    public static void main(String[] args) {
        CLibrary.INSTANCE.printf("Hello, World!\n");
    }   
}
