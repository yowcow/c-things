use v6;
use NativeCall;
use Test;

class MyNative {

    sub library { './libhello.so'; }

    our sub get-message(Str:D $name --> Str)
        is native(&library)
        is symbol('get_message')
        { * }

    class MemberT is repr('CStruct') {
        has int32 $.id;
        has Str $.name;
    }

    our sub create-member(int32 :$id, Str :$name --> MemberT)
        is native(&library)
        is symbol('create_member')
        { * }
}

is MyNative::get-message("Hoge"), "Hello world, Hoge";
is MyNative::get-message("あばば"), "Hello world, あばば";

{
    # Is this possible!?
    #my $res = MyNative::create-member(id => 123, name => 'hoge');
    #say $res.perl;
}

done-testing;
