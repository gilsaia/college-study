MOVE.B #255, D0
MOVE.W #6454,A0
MOVE.W A0,A1
ADD.W #128,A1
MOVE.W A1,A2
ADD.W #128,A2
MOVE.W A2,D1
ADD.W #128,D1
MOVE.W D1,D2
ADD.W #128,D2
MOVE.B #20,D3
FIRST: MOVE.B D0,(A0)
MOVE.B D0,(A1)
MOVE.B D0,(A2)
INC A0
INC A1
INC A2
DEC D3
BNE 16402
MOVE.W D1,A0
MOVE.W D2,A1
MOVE.B #20,D3
SECOND:MOVE.B D0,(A0)
MOVE.B D0,(A1)
INC A0
INC A1
DEC D3
BNE 16415
ADD #128,A1
DEC A1
MOVE.W A1,A0
DEC A1
MOVE.W A1,A2
DEC A2
MOVE.W A2,D1
DEC D1
MOVE.W D1,D2
DEC D2
MOVE.B #10,D3
THIRD:MOVE.B D0,(A0)
MOVE.B D0,(A1)
MOVE.B D0,(A2)
ADD #128,A0
ADD #128,A1
ADD #128,A2
DEC D3
BNE 16435
MOVE.W D1,A1
MOVE.W D2,A2
MOVE.B #10,D3
FOURTH:MOVE.B D0,(A1)
MOVE.B D0,(A2)
ADD #128,A1
ADD #128,A2
DEC D3
BNE 16451
FIVTH:SUB #19,A0
MOVE.W A0,A1
ADD.W #128,A1
MOVE.W A1,A2
ADD.W #128,A2
MOVE.W A2,D1
ADD.W #128,D1
MOVE.W D1,D2
ADD.W #128,D2
MOVE.B #20,D3
FIRST: MOVE.B D0,(A0)
MOVE.B D0,(A1)
MOVE.B D0,(A2)
INC A0
INC A1
INC A2
DEC D3
BNE 16476
MOVE.W D1,A0
MOVE.W D2,A1
MOVE.B #20,D3
SECOND:MOVE.B D0,(A0)
MOVE.B D0,(A1)
INC A0
INC A1
DEC D3
BNE 16489
ADD #128,A1
DEC A1
MOVE.W A1,A0
DEC A1
MOVE.W A1,A2
DEC A2
MOVE.W A2,D1
DEC D1
MOVE.W D1,D2
DEC D2
MOVE.B #10,D3
THIRD:MOVE.B D0,(A0)
MOVE.B D0,(A1)
MOVE.B D0,(A2)
ADD #128,A0
ADD #128,A1
ADD #128,A2
DEC D3
BNE 16509
MOVE.W D1,A1
MOVE.W D2,A2
MOVE.B #10,D3
FOURTH:MOVE.B D0,(A1)
MOVE.B D0,(A2)
ADD #128,A1
ADD #128,A2
DEC D3
BNE 16525
SUB #19,A0
SIXTH:MOVE.W A0,A1
ADD.W #128,A1
MOVE.W A1,A2
ADD.W #128,A2
MOVE.W A2,D1
ADD.W #128,D1
MOVE.W D1,D2
ADD.W #128,D2
MOVE.B #20,D3
FIRST: MOVE.B D0,(A0)
MOVE.B D0,(A1)
MOVE.B D0,(A2)
INC A0
INC A1
INC A2
DEC D3
BNE 16550
MOVE.W D1,A0
MOVE.W D2,A1
MOVE.B #20,D3
SECOND:MOVE.B D0,(A0)
MOVE.B D0,(A1)
INC A0
INC A1
DEC D3
BNE 16563