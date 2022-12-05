/*
 * HC32F46x.ld generic setup.
 */
MEMORY
{
    irom0  (rx) : org = 0x00008000, len = 448k
    iram1  (wx) : org = 0x20000000, len = 64k 
    iram2  (wx) : org = 0x20010000, len = 64k 
 }


