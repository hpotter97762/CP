import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class DemoClass {

	public static void main(String[] args) throws IOException {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(bf.readLine());
		String[] s=bf.readLine().split(" ");
		int[] cnt=new int[4];
		for(int i=0;i<n;++i)
			cnt[s[i].charAt(0)-'1']++;
		int ans=cnt[3]+cnt[2];
		cnt[0]-=Math.min(cnt[2],cnt[0]);
		ans+=cnt[1]/2;
		cnt[1]%=2;
		ans+=Math.ceil((cnt[0]+cnt[1]*2)*1.0/4);
		System.out.println(ans);
	}

}