<h2><a href="https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1">M-Coloring Problem</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">You are given an undirected graph consisting of <strong><code>v</code></strong>&nbsp;vertices and a list of&nbsp;<strong>edges</strong>, along with an integer&nbsp;<strong><code>m</code></strong>. Your task is to determine whether it is possible to color the graph using at most&nbsp;<code>m</code>&nbsp;different colors such that no two adjacent vertices share the same color. Return&nbsp;<code>true</code>&nbsp;if the graph can be colored with at most&nbsp;<code>m</code>&nbsp;colors, otherwise return&nbsp;<code>false</code>.<br></span></p>
<p><span style="font-size: 14pt;"><strong>Note:</strong>&nbsp;The graph is indexed with 0-based indexing.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
<strong>Output: </strong>true<strong>
Explanation: </strong>It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
Vertex 0: Color 3
Vertex 1: Color 2
Vertex 2: Color 1
Vertex 3: Color 2
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>v = 3, edges[] = [(0,1),(1,2),(0,2)], m = 2
<strong>Output: </strong>false<br><strong>Explanation: </strong>It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.</span></pre>
<p><span style="font-size: 14pt;"><strong>Expected Time Complexity:</strong> O(m<sup>V</sup>)</span><br><span style="font-size: 14pt;"><strong>Expected Auxiliary&nbsp;</strong><strong>Space:</strong> O(v<sup>2</sup>)</span></p>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ v ≤ 20<br>1 ≤ edges.size() ≤ (v*(v-1))/2<br>0 ≤ edges[i][j] ≤ n-1<br>1 ≤ m ≤ v</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Backtracking</code>&nbsp;<code>Algorithms</code>&nbsp;