`timescale 1ns / 1ps

//모듈 이름과 포트 리스트
module top();

    // wire, reg, 다른 변수들의 정의
    wire q, qbar;
    reg set, reset;
    
    // 하위 모듈에 대한 정의    
    SR_latch m1(q, qbar, ~set, ~reset);
    
    //작동 블럭
    initial
        begin
            $monitor($time, "set = %b, reset =%b,q=%b\n",set,reset,q);
            set = 0; reset = 0;
            #5 reset = 1;
            #5 reset = 0;
            #5 set = 1;
        end 
endmodule
