.include "m328def.inc" 
.org 0x0000
           RJMP begin; jump to begin  
.org 0x0034 
 begin:    CLI
           LDI    R16,low(RAMEND)
         OUT    SPL,R16
           LDI     R16,high(RAMEND)
         OUT    SPH, R16                
         LDI    R16,0xFF 
         OUT    DDRD, R16   
           LDI     R16,0xFF 
         OUT    PORTD, R16
           RCALL  Delay
           LDI     R16,0x00
         OUT     PORTD, R16
           RCALL  Delay
Delay:     LDI     R17, 0x02
loop:    DEC     R17
		BRNE    loop
//		RCALL loop2
//loop2:    DEC     R17
//		BRNE    loop2
//           BRNE    loop             
          RET 