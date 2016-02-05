use v6;
use NativeCall;
use Test;

class MyNative {

    sub library { './libhello.so'; }

    our sub get-message(Str:D $name --> Str)
        is native(&library)
        is symbol('get_message')
        { * }
}

is MyNative::get-message("Hoge"), "Hello world, Hoge";
is MyNative::get-message("あばば"), "Hello world, あばば";

done-testing;
