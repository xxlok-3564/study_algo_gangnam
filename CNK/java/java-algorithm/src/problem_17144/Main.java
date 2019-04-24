package problem_17144;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int[][] directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	static Scanner sc;
	static int R, C, T;
	static List<List<Integer>> board;
	static List<List<Integer>> adds;
	static List<Integer> puriLocation = new ArrayList<Integer>();
	static List<Integer> puriA;
	static List<Integer> puriB;
	
	private static void initAdds() {
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				adds.get(row).set(col, 0);
			}
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File("input.txt"), "UTF-8");
		// 입력 받기
		// 1. Row 수, Col 수, 시간
		R = sc.nextInt();
		C = sc.nextInt();
		T = sc.nextInt();
		
		board = new ArrayList<List<Integer>>();
		adds = new ArrayList<List<Integer>>();
		for (int row = 0; row < R; row++) {
			board.add(new ArrayList<Integer>());
			adds.add(new ArrayList<Integer>());
			for (int col = 0; col < C; col++) {
				board.get(row).add(sc.nextInt());
				adds.get(row).add(0);
				if (board.get(row).get(col) == -1) {// 공기청정기
					puriLocation.add(row);
					puriLocation.add(col);
				}
			}
		}
		
				
		puriA = getRotationUp(puriLocation.get(0), puriLocation.get(1));
		puriB = getRotationDown(puriLocation.get(2), puriLocation.get(3));
		
		
		for (int time = 0; time < T; time++) {			
			
			// 확산 하기
			// 미세먼지가 동시에 퍼진다.
			// boards를 기준으로 adds에 추가될 미세먼지 추가
			for (int row = 0; row < R; row++) {
				for (int col = 0; col < C; col++) {
					if (board.get(row).get(col) > 0) {
						spared(row, col);
					}
				}
			}			
			
			for (int row = 0; row < R; row++) {
				for (int col = 0; col < C; col++) {
					if (adds.get(row).get(col) > 0) {
						board.get(row).set(col, board.get(row).get(col) + adds.get(row).get(col));
					}
				}
			}
			
			
			puriStart(puriA);
			puriStart(puriB);
			
			showMatrix(board);
			initAdds();
		}
		
		getBoardTot();
		
	}

	private static void getBoardTot() {
		int tot = 0;
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				if (board.get(row).get(col) > 0) {
					tot += board.get(row).get(col);
				}
			}
		}
		System.out.println(tot);
	}

	private static void puriStart(List<Integer> puriRotations) {
		for (int i = 0; i < puriRotations.size() - 2; i+=2) {
			int nowRow = puriRotations.get(i);
			int nowCol = puriRotations.get(i+1);
			int nextRow = puriRotations.get(i+2);
			int nextCol = puriRotations.get(i+3);
			
			if (board.get(nowRow).get(nowCol) >= 0) {
				board.get(nowRow).set(nowCol, board.get(nextRow).get(nextCol));
			}
			
			if (board.get(nextRow).get(nextCol) == -1) {
				board.get(nowRow).set(nowCol, 0);
			}
		}
	}
	
	private static List<Integer> getRotationUp(int row, int col) {
		List<Integer> rotations = new ArrayList<Integer>();
		int nowRow = row;
		int nowCol = col;
		
		rotations.add(nowRow);
		rotations.add(nowCol);
		while (nowRow > 0) {
			nowRow--;
			rotations.add(nowRow);
			rotations.add(nowCol);			
		}
		
		while (nowCol < C - 1) {
			nowCol++;
			rotations.add(nowRow);
			rotations.add(nowCol);			
		}
		
		while (nowRow < row) {
			nowRow++;
			rotations.add(nowRow);
			rotations.add(nowCol);
		}		
		
		while (nowCol > 0 ) {
			nowCol--;
			rotations.add(nowRow);
			rotations.add(nowCol);
		}
		
			
		return rotations;
	}
	
	private static List<Integer> getRotationDown(int row, int col) {
		List<Integer> rotations = new ArrayList<Integer>();
		int nowRow = row;
		int nowCol = col;
		
		rotations.add(nowRow);
		rotations.add(nowCol);
		while (nowRow < R - 1) {
			nowRow++;
			rotations.add(nowRow);
			rotations.add(nowCol);			
		}
		
		while (nowCol < C - 1) {
			nowCol++;
			rotations.add(nowRow);
			rotations.add(nowCol);
		}
		
		while (nowRow > row) {
			nowRow--;
			rotations.add(nowRow);
			rotations.add(nowCol);
		}
		
		while (nowCol > 0) {
			nowCol--;
			rotations.add(nowRow);
			rotations.add(nowCol);
		}
		
		
		return rotations;
	}

	private static void spared(int row, int col) {
		int munjiYang = board.get(row).get(col) / 5;
		
		for (int d = 0; d < 4; d++) {
			int tmpRow = row + directions[d][0];
			int tmpCol = col + directions[d][1];			

			if (tmpRow >= 0 && tmpRow < R && tmpCol >= 0 && tmpCol < C) {
				if (board.get(tmpRow).get(tmpCol) != -1) {
					adds.get(tmpRow).set(tmpCol, adds.get(tmpRow).get(tmpCol) + munjiYang);
					board.get(row).set(col, board.get(row).get(col) - munjiYang);
				}				
			}
		}
	}
	
	private static void showMatrix(List<List<Integer>> matrix) {
		for (int row = 0; row < matrix.size(); row++) {
			for (int col = 0; col < matrix.get(row).size(); col++) {
				System.out.printf("%4d ", matrix.get(row).get(col));
			}
			System.out.println();
		}
		System.out.println();
	}
	
	
}
