
public class ReplaceSpaceSolution {
	
	public String replaceSpace(StringBuffer str) {
        int orignalLength = str.length();
        int numberOfSpace = 0;
        //统计字符串中的空格数量
        for(int i = 0; i < orignalLength; i++) {
            if(str.charAt(i) == ' ') {
                ++numberOfSpace;
            }                  
        }
         
        int newLength = orignalLength + numberOfSpace*2;
        str.setLength(newLength);
         
        int indexOfOrignal = orignalLength-1;
        int indexOfNew = newLength-1;
        while(indexOfOrignal >= 0 && indexOfNew >= indexOfOrignal) {
            if(str.charAt(indexOfOrignal) == ' ') {
                str.setCharAt(indexOfNew--, '0');
                str.setCharAt(indexOfNew--, '2');
                str.setCharAt(indexOfNew--, '%');
                             
            }
            else {
                str.setCharAt(indexOfNew--, str.charAt(indexOfOrignal));
            }
            --indexOfOrignal;
        }
        return str.toString();
         
    }

}
