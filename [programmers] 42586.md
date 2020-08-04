## [기능 개발](https://programmers.co.kr/learn/courses/30/lessons/42586)

* 각 단계에서 걸리는 시간을 계산
* 현재 기능에서 걸리는 시간 < 이전 기능에서 걸리는 시간인 경우 함께 배포
* 시간복잡도 O(N)
* 기능 배포 함수의 배열 갯수가 몇개가 될지 알 수 없으므로 list로 구한 뒤 마지막에 mapToInt로 int 배열로 바꿔준다.

```java

import java.util.*;
class Solution {
	public int[] solution(int[] progresses, int[] speeds) {
		LinkedList<Integer> list = new LinkedList<Integer>();

		int length = progresses.length;
		int finishedService = 1;
		int time = calcTime(progresses[0], speeds[0]);

		for (int i = 1; i < length; i++) {
			int newTime = calcTime(progresses[i], speeds[i]);
			if (time >= newTime) {
				finishedService++;
			} else {
				list.add(finishedService);
				finishedService = 1;
				time = newTime;
			}

			if (i == length - 1) {
				list.add(finishedService);
			}
		}

		return list.stream().mapToInt(x -> x).toArray();
	}

	public int calcTime(int progress, int speed) {
		return (int) Math.ceil((100 - progress) / (double) speed);
	}
}

```