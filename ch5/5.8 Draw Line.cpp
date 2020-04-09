class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> scrn(length, 0);
        const int iSize = sizeof(int) * 8;
        const int iPerLine = w / iSize;
        int beginByte = x1 / iSize, beginOffset = x1 % iSize;
        int endByte = x2 / iSize, endOffset = x2 % iSize;
        if(beginOffset != 0) beginByte++;
        if(endOffset != iSize - 1) endByte--;
        for(int b = beginByte; b <= endByte; b++)
        {
            scrn[iPerLine * y + b] = 0xFFFFFFFF;
        }
        unsigned int beginMask = 0xFFFFFFFF >> beginOffset;
        unsigned int endMask = 0xFFFFFFFF << (iSize - endOffset - 1);
        if(x1 / iSize == x2 / iSize){
            scrn[iPerLine * y + x1 / iSize] = beginMask & endMask;
        }
        else{
            if(beginOffset != 0){
                scrn[iPerLine * y + beginByte - 1] = beginMask;
            }
            if(endOffset != iSize - 1){
                scrn[iPerLine * y + endByte + 1] = endMask;
            }
        }
        return scrn;
    }
};
