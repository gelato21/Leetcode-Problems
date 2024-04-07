<h2><a href="https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint">Lexicographically Smallest String After Operations With Constraint</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>Define a function <code>distance(s<sub>1</sub>, s<sub>2</sub>)</code> between two strings <code>s<sub>1</sub></code> and <code>s<sub>2</sub></code> of the same length <code>n</code> as:</p>

<ul>
	<li>The<strong> sum</strong> of the <strong>minimum distance</strong> between <code>s<sub>1</sub>[i]</code> and <code>s<sub>2</sub>[i]</code> when the characters from <code>&#39;a&#39;</code> to <code>&#39;z&#39;</code> are placed in a <strong>cyclic</strong> order, for all <code>i</code> in the range <code>[0, n - 1]</code>.</li>
</ul>

<p>For example, <code>distance(&quot;ab&quot;, &quot;cd&quot;) == 4</code>, and <code>distance(&quot;a&quot;, &quot;z&quot;) == 1</code>.</p>

<p>You are allowed to perform <strong>any</strong> number of operations on <code>s</code>. In each operation, you can <strong>change</strong> a letter of <code>s</code> to <strong>any</strong> other lowercase English letter.</p>

<p>Return <em>a string denoting the <strong><span data-keyword="lexicographically-smaller-string">lexicographically smallest</span></strong> string </em><code>t</code><em> you can get after some operations, such that </em><code>distance(s, t) &lt;= k</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;zbbz&quot;, k = 3
<strong>Output:</strong> &quot;aaaz&quot;
<strong>Explanation: </strong>In this example, we can perform the following operations:
Change s[0] to &#39;a&#39;, s becomes &quot;abbz&quot;.
Change s[1] to &#39;a&#39;, s becomes &quot;aabz&quot;.
Change s[2] to &#39;a&#39;, s becomes &quot;aaaz&quot;.
The distance between &quot;zbbz&quot; and &quot;aaaz&quot; is equal to k = 3.
It can be shown that &quot;aaaz&quot; is the lexicographically smallest string achievable after any number of operations.
Hence, the answer is &quot;aaaz&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;xaxcd&quot;, k = 4
<strong>Output:</strong> &quot;aawcd&quot;
<strong>Explanation:</strong> In this example, we can perform the following operations:
Change s[0] to &#39;a&#39;, s becomes &quot;aaxcd&quot;.
Change s[2] to &#39;w&#39;, s becomes &quot;aawcd&quot;.
The distance between &quot;xaxcd&quot; and &quot;aawcd&quot; is equal to k = 4.
It can be shown that &quot;aawcd&quot; is the lexicographically smallest string achievable after any number of operations.
Hence, the answer is &quot;aawcd&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;lol&quot;, k = 0
<strong>Output:</strong> &quot;lol&quot;
<strong>Explanation: </strong>In this example, k = 0, and changing any character makes the distance greater than 0.
Hence, the answer is &quot;lol&quot;.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
