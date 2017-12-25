using System;
using System.IO;

namespace hacker_space_prob
{
	static class Problem
	{
		private struct cmpr
		{
			public int a;
			public int b;

			public void Init()
			{
				a = 0; b = 0;
			}
		}

		private struct triplet 
		{
			public int zed;
			public int one;
			public int two;

			public void Init()
			{
				zed = 0; one = 0; two = 0;
			}
		}

		static private cmpr compare(ref triplet a, ref triplet b)
		{
			cmpr Comparison = new cmpr();
			Comparison.Init ();

			if (a.zed > b.zed) {
				Comparison.a ++;
			} else if (a.zed < b.zed) {
				Comparison.b ++;
			}

			if (a.one > b.one) {
				Comparison.a ++;
			}
			else if (a.one < b.one){
				Comparison.b ++;
			}

			if (a.two > b.two) {
				Comparison.a ++;
			}
			else if (a.two < b.two){
				Comparison.b ++;
			}

			return Comparison;
		}

		public static void Main(String[] args)
		{
			bool a_valid = false;
			bool b_valid = false;
			string[] tokens_a0 = Console.ReadLine().Split(' ');
			string[] tokens_b0 = Console.ReadLine().Split(' ');
			triplet a = new triplet();
			a.Init ();
			triplet b = new triplet();
			b.Init ();
			if (!String.IsNullOrEmpty (tokens_a0 [0]) && !String.IsNullOrEmpty (tokens_a0 [1]) && !String.IsNullOrEmpty (tokens_a0 [2]))
			{
				a.zed = Convert.ToInt32 (tokens_a0 [0]);
				a.one = Convert.ToInt32 (tokens_a0 [1]);
				a.two = Convert.ToInt32 (tokens_a0 [2]);
				a_valid = true;
			} else
			{
				Console.WriteLine ("Error reading triplet A");
			}

			if (!String.IsNullOrEmpty (tokens_a0 [0]) && !String.IsNullOrEmpty (tokens_a0 [1]) && !String.IsNullOrEmpty (tokens_a0 [2]))
			{
				b.zed = Convert.ToInt32 (tokens_b0 [0]);
				b.one = Convert.ToInt32 (tokens_b0 [1]);
				b.two = Convert.ToInt32 (tokens_b0 [2]);
				b_valid = true;
			} else
			{
				Console.WriteLine ("Error reading triplet B");
			}

			if (a_valid && b_valid)
			{
				cmpr result = compare (ref a, ref b);
				Console.WriteLine (result.a.ToString () + " " + result.b.ToString ());
			}
		}
	}
}