import myjavalibrary.MyJavaAPI;
import myjavalibrary.MyJavaLibrary;

public class TestDriver {

    public static void main(String[] args) {
        MyJavaAPI api = MyJavaLibrary.getAPI();
        int val = api.calc(2);
        String name = api.getName();
        api.log("Value: " + val + ", Name: " + name);
    }
}
