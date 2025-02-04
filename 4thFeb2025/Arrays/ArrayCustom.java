public class ArrayCustom {
    private ArrayCustom () {}

    // adding new item to beginning of a array of int type
    // Input: an array, new element
    // Output: returns new modified array, doesn't modify original array
    public static int[] addItemToBeginning (int[] arr, int element) {
        int[] tempArr = Arrays.copyOf (arr, arr.length + 1);
        
        tempArr[0] = element;
        System.arraycopy (arr, 0, tempArr, 1, arr.length);

        return tempArr;
    }    
}
