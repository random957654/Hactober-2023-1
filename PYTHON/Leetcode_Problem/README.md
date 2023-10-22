<h2><a href="https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1">Minimize the Heights II</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong>&nbsp;denoting heights of <strong>N</strong> towers and a positive integer <strong>K. </strong></span></p>
<p><span style="font-size: 18px;">For <strong>each </strong>tower, you must perform <strong>exactly one</strong> of the following operations <strong>exactly once</strong>.</span></p>
<ul>
<li><span style="font-size: 18px;"><strong>Increase </strong>the height of the tower by <strong>K</strong></span></li>
<li><span style="font-size: 18px;"><strong>Decrease </strong>the height of the tower by <strong>K</strong></span></li>
</ul>
<p><span style="font-size: 18px;">Find out the <strong>minimum </strong>possible difference between the height&nbsp;of the shortest and tallest towers after you have modified each tower.</span></p>
<p><span style="font-size: 18px;">You can find a slight modification of the problem&nbsp;<a href="https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/">here</a>.<br><strong>Note:</strong> It is <strong>compulsory </strong>to increase or decrease the height by K for each tower. <strong>After</strong> the operation, the resultant array should <strong>not</strong> contain any <strong>negative integers</strong>.</span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>K = 2, N = 4
Arr[] = {1, 5, 8, 10}
<strong>Output:</strong>
5
<strong>Explanation:</strong>
The array can be modified as <br>{1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. <br>The difference between 
the largest and the smallest is 8-3 = 5.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
<strong>Output:</strong>
11
<strong>Explanation:</strong>
The array can be modified as<br></span><span style="font-size: 18px;">{3+k, 9+k, 12-k, 16-k, 20-k} -&gt; {6,&nbsp;12,&nbsp;9,&nbsp;13,&nbsp;17}. <br>The difference between 
the largest and the smallest is 17-6 = 11.&nbsp;
</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>getMinDiff()</strong>&nbsp;which takes the <strong>arr[], n,</strong>&nbsp;and&nbsp;<strong>k&nbsp;</strong>as input parameters and returns an integer&nbsp;denoting the minimum difference.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N*logN)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N)<br><br><strong>Constraints</strong><br>1 ≤ K&nbsp;≤ 10<sup>4</sup><br>1 ≤ N&nbsp;≤ 10<sup>5</sup><br>1 ≤ Arr[i] ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Greedy</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;
