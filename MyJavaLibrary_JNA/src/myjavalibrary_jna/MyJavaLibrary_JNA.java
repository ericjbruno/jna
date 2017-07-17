package myjavalibrary_jna;

import com.sun.jna.Callback;
import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;
import myjavalibrary.*;

/**
 * @author ericjbruno
 */
public class MyJavaLibrary_JNA implements MyJavaAPI {

    // JNA reverse callback code
    //
    public static class MyJavaAPI_C {
        interface reg_calc_callback extends Callback {
            int invoke(int val);
        }
        interface reg_getName_callback extends Callback {
            String invoke();
        }
        interface reg_log_callback extends Callback {
            void invoke(String val);
        }
        
        public static native void reg_calc_cb(reg_calc_callback func);
        public static native void reg_getName_cb(reg_getName_callback func);
        public static native void reg_log_cb(reg_log_callback func);

        static {
            Native.register("MyJavaLibrary_C");
        }
    }
    
    public static MyJavaAPI_C.reg_calc_callback reg_calc_func = 
            new MyJavaAPI_C.reg_calc_callback() {
        public int invoke(int val) {
            return INSTANCE.calc(val);
        }
    };    
    
    public static MyJavaAPI_C.reg_getName_callback reg_getName_func = 
            new MyJavaAPI_C.reg_getName_callback() {
        public String invoke() {
            return INSTANCE.getName();
        }
    };

    public static MyJavaAPI_C.reg_log_callback reg_log_func = 
            new MyJavaAPI_C.reg_log_callback() {
        public void invoke(String val) {
            INSTANCE.log(val);
        }
    };    

    /////////////////////////////////////////////////////////////////////////
    
    private static MyJavaLibrary_JNA INSTANCE = new MyJavaLibrary_JNA();
    public static MyJavaAPI getAPI() { return INSTANCE; }
    
    /////////////////////////////////////////////////////////////////////////

    public static void main(String[] args) {
        System.out.println("in main()");
    }

    private MyJavaLibrary_JNA() { 
        // Register callbacks with JNA C library
        MyJavaAPI_C.reg_calc_cb(reg_calc_func);
        MyJavaAPI_C.reg_getName_cb(reg_getName_func);
        MyJavaAPI_C.reg_log_cb(reg_log_func);
        System.out.println("MyJavaLibrary_JNA(): callbacks registered, " + this);
    }

    /////////////////////////////////////////////////////////////////////////

    private MyJavaAPI myJavaAPI = 
        MyJavaLibrary.getAPI();

    @Override
    public int calc(int value) {
        return myJavaAPI.calc(value);
    }

    @Override
    public String getName() {
        return myJavaAPI.getName();
    }

    @Override
    public void log(String s) {
        myJavaAPI.log(s);
    }
}
