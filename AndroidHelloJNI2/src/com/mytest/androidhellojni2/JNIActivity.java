package com.mytest.androidhellojni2;

import java.io.UnsupportedEncodingException;
import java.text.DecimalFormat;


//import com.example.bloutoothtest.R;

import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class JNIActivity extends Activity {
	private Button add;
	private TextView textView;
	static {
		System.loadLibrary("nativecryptowrapper"); // "myjni.dll" in Windows,
													// "libmyjni.so" in Unixes
		// System.loadLibrary("cryptopp");
	}

	// A native method that returns a Java String to be displayed on the
	// TextView
	public native double getMessage();

	public native String testSchnorr();

	public native byte[] byteTest();

	// private native double average(int n1, int n2);
	// private native String sayHello(String msg);

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_jni);
		// Create a TextView.
		add = (Button) findViewById(R.id.button1);

		textView = new TextView(this);
		byte[] result = byteTest();
		// String result_str = result.toString();
		String str = "";
		try {
			str = new String(result, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		byte[] result2 = byteTest();
		String str2 = "";
		try {
			str2 = new String(result2, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		String a = new StringBuilder(str).append( " a po podnownym uruchomieniu " ).append(str2).toString();
		
//		str = str + " a po podnownym uruchomieniu " + str2;
		textView.setText(a);
//		setContentView(textView);
		// new AlertDialog.Builder(this).setMessage(result).show();

	}

	public void add(View view) {
		byte[] result = byteTest();
		// String result_str = result.toString();
		String str = "";
		try {
			str = new String(result, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		textView.setText(str);
		setContentView(textView);
	}
}
