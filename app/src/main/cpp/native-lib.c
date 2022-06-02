#include <jni.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

//can be separated to textlcd.h
#ifndef TEXTLCD_H_
#define TEXTLCD_H_

#define TEXTLCD_ON        1
#define TEXTLCD_OFF    2
#define TEXTLCD_INIT   3
#define TEXTLCD_CLEAR  4

#define TEXTLCD_LINE1  5
#define TEXTLCD_LINE2  6

#endif

static int fd;
static int fdd;


//textLCD
JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_on
        (JNIEnv * env, jobject obj){
    if (fd == 0)
        fd = open("/dev/fpga_textlcd", O_WRONLY);
    assert(fd != 0);

    ioctl(fd, TEXTLCD_ON);
}

JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_off
        (JNIEnv * env, jobject obj){
    if (fd )
    {
        ioctl(fd, TEXTLCD_OFF);
        close(fd);
    }

    fd = 0;
}

JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_initialize
        (JNIEnv * env, jobject obj){
    if (fd == 0)
        fd = open("/dev/fpga_textlcd", O_WRONLY);
    assert(fd != -1);

    ioctl(fd, TEXTLCD_INIT);
}

JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_clear
        (JNIEnv * env, jobject obj){
    //if (fd )
    ioctl(fd, TEXTLCD_CLEAR);
}

JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_print1Line
        (JNIEnv * env, jobject obj, jstring msg){
    const char *str;

    if (fd )
    {
        str = (*env)->GetStringUTFChars(env, msg, 0);
        ioctl(fd, TEXTLCD_LINE1);
        write(fd, str, strlen(str));
        (*env)->ReleaseStringUTFChars(env, msg, str);
    }

}

JNIEXPORT void JNICALL Java_com_example_rpstest2_TextLCD_print2Line
(JNIEnv * env, jobject obj, jstring msg){
    const char *str;

    if (fd )
    {
        str = (*env)->GetStringUTFChars(env, msg, 0);
        ioctl(fd, TEXTLCD_LINE2);
        write(fd, str, strlen(str));
        (*env)->ReleaseStringUTFChars(env, msg, str);
    }
}
