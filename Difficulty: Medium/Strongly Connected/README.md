<h2><a href="https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1">Strongly Connected</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given&nbsp;</span><span style="font-size: 18px;">an adjacency list, </span><strong style="font-size: 18px;">adj&nbsp;</strong><span style="font-size: 18px;">of <strong>D</strong></span><strong style="font-size: 18px;">irected Graph</strong>, <span style="font-size: 18px;">Find </span><span style="font-size: 18px;">the number of strongly connected components in the graph.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>adj[][] = [[2, 3], [0], [1], [4], []]</span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/89b7c4e7-e03c-402f-b445-3e8815299af6_1685086635.png" alt="">
<span style="font-size: 18px;"><strong>Output: </strong>3
<strong>Explanation</strong>: We can clearly see that there are 3 Strongly Connected Components in the Graph.
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/9f4ccc7f-8ad8-4f81-908a-01f27090ba5e_1685086635.png" alt="">&nbsp;</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong></span><span style="font-size: 18px;">adj[][] = [[1], [2], [0]]</span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700394/Web/Other/8b9b3908-a800-4ffa-acaf-26cb760eac8e_1685086635.png" alt="">
<span style="font-size: 18px;"><strong>Output: </strong>1
<strong>Explanation</strong>:</span> <span style="font-size: 18px;">All of the nodes are connected to each other. So, there's only one SCC.<br></span></pre>
<pre><strong>Input: </strong>adj[][] = [[1], []]
<strong>Output: </strong>2</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2&lt;=adj.size()&lt;=10<sup>6</sup><br>0&lt;=edges&lt;=adj.size()-1</span></p></div>