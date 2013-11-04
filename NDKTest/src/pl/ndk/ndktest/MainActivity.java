package pl.ndk.ndktest;

import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.view.Menu;

public class MainActivity extends Activity {

	// load the library - name matches jni/Android.mk 
	  static {
	    System.loadLibrary("diffieHellman");
	  }
	   
	  // declare the native code function - must match ndkfoo.c
	  private native String invokeNativeFunction();
	   
	  @Override
	    public void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.activity_main);
	         
	        // this is where we call the native code
	        String hello = invokeNativeFunction();
	         
	        new AlertDialog.Builder(this).setMessage(hello).show();
	    }
    
}
