package com.example.kamlesh.afinal;

import android.annotation.SuppressLint;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;

public class MainActivity extends AppCompatActivity {
    private EditText el;
    private TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        el = (EditText)findViewById(R.id.editText);
        tv = (TextView)findViewById(R.id.textView);

    }
    public void send_data(View view){
//        String message = el.getText().toString();
        String message = "hello from vivo Y51L";
        tv.setText(message);
        BackRoundTask bl = new BackRoundTask();
        bl.execute(message);
        System.out.print(message);
    }

    class BackRoundTask extends AsyncTask<String,Void,Void>
    {
        Socket s;
        PrintWriter writer;


        @Override
        protected Void doInBackground(String... voids) {
            try {
//                tv.setText("hello from background");
                String message = voids[0];
//                s =new Socket("172.27.27.10",8888);
                s =new Socket("172.24.240.41",9876);
                writer = new PrintWriter(s.getOutputStream());
                writer.write(message);
                writer.flush();
                writer.close();

            } catch (IOException e) {
                e.printStackTrace();
            }


            return null;
        }
    }


}
