package problem_17140;

import java.io.File;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * 이차원 배열과 연산
 * https://www.acmicpc.net/problem/17140
 */
public class Main {
	static Scanner sc;
	static File file = new File("input.txt");	
	static InputStream inputStream = System.in;
	
	static int r, c, k; // 배열 행, 배열 열, 특정값이 k가 되야한다.	
	static int[][] board;
	static int maxRow;
	static int maxCol;
	
	private static void init() {
		r = sc.nextInt();
		c = sc.nextInt();
		k = sc.nextInt();
		
		board = new int[100][100];
		maxRow = 3;
		maxCol = 3;
		for (int row = 0; row < maxRow; row++) {			
			for (int col = 0; col < maxCol; col++) {
				board[row][col] = sc.nextInt();
			}
		}
	}
		
	private static List<Integer> generateList(List<Integer> numbers) {
		Map<Integer, Integer> counts = new TreeMap<Integer, Integer>();
		
		for (int i = 0; i < numbers.size(); i++) {
			int number = numbers.get(i);
			if (number == 0) {
				continue;
			}			
						
			if (!counts.containsKey(number)) {
				counts.put(number, 0);
			}			
			counts.put(number, counts.get(number) + 1);
		}
		
		List<Bind> tmpRes = new ArrayList<Bind>();
		for (Entry<Integer, Integer> e : counts.entrySet()) {
			tmpRes.add(new Bind(e.getKey(), e.getValue()));
		}
		Collections.sort(tmpRes);
		
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 0; i < tmpRes.size(); i++) {
			res.add(tmpRes.get(i).num);
			res.add(tmpRes.get(i).cnt);
		}
		
		return res;
	}
	
	private static void calR() {
		maxCol = 0;
		for (int row = 0; row < 100; row++) {
			List<Integer> numbers = new ArrayList<Integer>();
			for (int col = 0; col < 100; col++) {
				numbers.add(board[row][col]);
			}
			
			numbers = generateList(numbers);
			if (maxCol < numbers.size()) {
				maxCol = numbers.size();
			}
			for (int col = 0; col < 100; col++) {
				if (col < numbers.size()) {
					board[row][col] = numbers.get(col);
				} else {
					board[row][col] = 0;
				}
			}
		}
	}
	
	private static void calC() {
		maxRow = 0;
		for (int col = 0; col < 100; col++) {
			List<Integer> numbers = new ArrayList<Integer>();
			for (int row = 0; row < 100; row++) {
				numbers.add(board[row][col]);
			}
			
			numbers = generateList(numbers);
			if (maxRow < numbers.size()) {
				maxRow = numbers.size();
			}
			
			for (int row = 0; row < 100; row++) {
				if (row < numbers.size()) {
					board[row][col] = numbers.get(row);
				} else {
					board[row][col] = 0;
				}
			}
		}
	}
	
	private static void startWhatCal() {
		if (maxRow >= maxCol) {
			calR();
		} else {
			calC();
		}
	}
	
	public static void main(String[] args) throws Exception {
		sc = new Scanner(file, "UTF-8");
//		sc = new Scanner(inputStream);
		
		int ans = 0;
		init();		
		
		if (board[r-1][c-1] == k) {
			System.out.println(ans);
			return;
		}
		
		for (int i = 1; i <= 100; i++) {			
			startWhatCal();
			
			if (board[r-1][c-1] == k) {
				ans = i;
				System.out.println(ans);
				return;
			}			
		}
		
		ans = -1;
		System.out.println(ans);
	}

}

class Bind implements Comparable<Bind> {
	int num;
	int cnt;
	
	Bind(int num, int cnt) {
		this.num = num;
		this.cnt = cnt;
	}
	
	@Override
	public int compareTo(Bind o) {
		if (cnt < o.cnt) {
			return -1;
		} else if (cnt == o.cnt) {
			if (num < o.num) {
				return -1;
			}
			return 1;
		} else {
			return 1;
		}
	}	
}
