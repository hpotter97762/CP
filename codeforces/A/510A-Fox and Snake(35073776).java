import java.util.Scanner;

public class DemoClass {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String[] s=sc.nextLine().split(" ");
		int n=Integer.parseInt(s[0]),m=Integer.parseInt(s[1]);
		for(int i=0;i<n;++i) {
			if(i%2==1) {
				if(i%4==3)
					System.out.print('#');
				for(int j=0;j<m-1;++j)
					System.out.print('.');
				if(i%4==1)
					System.out.print('#');
			}
			else {
				for(int j=0;j<m;++j)
					System.out.print('#');
				
			}
			System.out.println();
		}
	}

}