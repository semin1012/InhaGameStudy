using System.Collections;
using System.Collections.Generic;
using UnityEngine;


namespace Chapter.SpatialPartition
{
	public class SegmentMarker : MonoBehaviour
	{
		private void OnTiggerExit(Collider other)
		{
			if (other.GetComponent<BikeController>())
				Destroy(transform.parent.gameObject);
		}
	}

}
