������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��

ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].

ʾ�� 2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
 
��ʾ��
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= start[i] <= end[i] <= 10^4
-------------------------------------------
û�к���ȷ��˼·��ֻ�ܲ���ģ����뷨��

�ȰѶ�ά���鰴���׸����ֵ�˳�����кã��������佻��͸������ֵ��û�����佻�������һ�����䡣

ʱ�临�Ӷ���O(n+logN)���ռ临�Ӷ���O(n)����������д�Ŀռ临�Ӷ���O(1)��Ŀǰ�벻������ôд��