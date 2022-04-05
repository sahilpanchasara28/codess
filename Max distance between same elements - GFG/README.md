# Max distance between same elements
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:20px">Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.</span></p>

<p><span style="font-size:20px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input</strong></span><span style="font-size:20px">
n= 6
arr = {1, 1, 2, 2, 2, 1}</span>

<span style="font-size:20px"><strong>Output</strong>
5</span>

<span style="font-size:20px"><strong>Explanation</strong>
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5</span></pre>

<p><span style="font-size:20px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input</strong>
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}</span>

<span style="font-size:20px"><strong>Output</strong>
10</span>

<span style="font-size:20px"><strong>Explanation</strong></span>



<span style="font-size:20px">arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete <strong>maxDistance() </strong>function which takes both the given array and their size as function arguments and returns the maximum distance between 2 same elements. </span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity </strong>: O(N)<br>
<strong>Expected Auxilliary Space</strong> : O(N)</span></p>

<p><span style="font-size:20px"><strong>Constraints:</strong></span></p>

<p><span style="font-size:20px">1&lt;=N&lt;=10<sup>6</sup></span></p>

<p>&nbsp;</p>

<p>&nbsp;</p>
 <p></p>
            </div>