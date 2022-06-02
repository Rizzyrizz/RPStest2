package com.example.rpstest2;

public class TextLCD {
    static {
        System.loadLibrary("rpstest2");
    }


    public native void on();
    public native void off();
    public native void initialize();
    public native void clear();

    public native void print1Line(String str);
    public native void print2Line(String str);

}

