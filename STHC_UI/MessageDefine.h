#ifndef MESSAGEDEFINE_H
#define MESSAGEDEFINE_H

/*
00421000  set 2번Attr 16

sendTemp.append((char)0x00);
sendTemp.append((char)0x42); get -> + 0x80, set -> + 0x40, attr1 -> + 0x01, attr2 -> 0x02, attr3 -> 0x03
sendTemp.append((char)0x10); 실제 값.
sendTemp.append((char)0x00);
*/


#define MESSAGE_OPTION_GET      0x80
#define MESSAGE_OPTION_SET      0x40

#define ATTRIBUTE_FIRST             0x01
#define ATTRIBUTE_SECOND         0x02
#define ATTRIBUTE_THIRD             0x03




#endif // MESSAGEDEFINE_H
