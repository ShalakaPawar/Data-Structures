class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack();
        String[] splitArray = path.split("/");
        String simplifiedPath = "";
        for(String dir : splitArray){
            if(dir.equals("") || dir.equals(".") || ((dir.equals("..")) && stack.isEmpty())){
                continue;
            }else if (dir.equals("..") && stack.size() > 0){
                stack.pop();
            } else {
                stack.push(dir);
            }
        }
    
        return "/" + String.join("/", stack); 
    }
}