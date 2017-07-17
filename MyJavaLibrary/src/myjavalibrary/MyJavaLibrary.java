package myjavalibrary;

/**
 * @author ericjbruno
 */
public class MyJavaLibrary implements MyJavaAPI {
    private static  MyJavaLibrary INSTANCE = new MyJavaLibrary();
    public static MyJavaAPI getAPI() { return INSTANCE; }
    
    ////////

    public static void main(String[] args) {
    }

    private MyJavaLibrary() { 
        System.out.println("MyJavaLibrary created ");
    }
    
    @Override
    public int calc(int value) {
        int ret = value * 2;
        System.out.println("In MyJavaLibrary: calc(value="+value+"), return="+ret);
        return ret;
    }

    @Override
    public String getName() {
        String ret = "Eric J. Bruno";
        System.out.println("In MyJavaLibrary: getName(), return="+ret);
        return ret;
    }

    @Override
    public void log(String s) {
        System.out.println("MyJavaLibrary.log: " + s);
    }
    
}
