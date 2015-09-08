//寻找字符串中，第一个只出现一次的字符
public class FirstNotRepeatingCharSolution {
	public int FirstNotRepeatingChar(String str) {
		int length = str.length();
		if(str == null || length == 0) return -1;
		
		int [] hashTable = new int[256];
		for(int i=0; i < length; ++i) {
			
			int ascii = (int)(str.charAt(i));
			hashTable[ascii]++;
		}
		
		for(int i=0; i< length; ++i) {
			int ascii = (int)(str.charAt(i));
			if(hashTable[ascii] == 1) {
				return i;
			}
		}
        return -1;
    }
}

class Test3 {
	public static void main(String[] args) {
		FirstNotRepeatingCharSolution test = new FirstNotRepeatingCharSolution();
		String str="hello,worldh";
		int index = test.FirstNotRepeatingChar(str);
		System.out.println(index);
	}
}
