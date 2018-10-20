Distinct keyword complexity : 	time - O(N) ,  
								space - O(N)
Top keyword complexity :    time: O(Nlog(D)) where N is size of data and, D is number of top results required(result of partial_sort_copy)
							space : O(N)


Assumptions :
Timestamp cannot be 0 or negative.
There is no intelligent way to compare queries, standard string compare will be used to compare queries
