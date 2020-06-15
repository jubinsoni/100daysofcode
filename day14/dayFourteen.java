public class dayFourteen
{
	public static void main(String args[])
	{
		String str = "ABC";
		dayFourteen stringMethods = new dayFourteen();
		stringMethods.allPair(str,"",0);
		System.out.println();
		stringMethods.permute(str,0,str.length()-1);
		System.out.println();
	}

	
	public void allPair(String str,String curr,int index)
	{
		if(str.length() == index)
		{
			System.out.print(curr + " ");
			return;
		}

		allPair(str,curr,index+1);
		allPair(str,curr+str.charAt(index),index+1);
	}

	public String swap(String str, int i, int j) 
    {
    	char[] charArr = str.toCharArray(); 
        char temp = charArr[i] ; 
        charArr[i] = charArr[j]; 
        charArr[j] = temp; 
        return new String(charArr); 
    }

	public void permute(String str,int l,int r)
	{
		if(l == r)
		{
			System.out.print(str + " ");
		}
		else
		{
			for(int i=l;i<=r;i++)
			{
				str = swap(str,l,i);
				permute(str,l+1,r);
				str = swap(str,l,i);
			}
		}
	}
}