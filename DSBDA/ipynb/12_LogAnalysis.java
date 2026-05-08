import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class LogAnalysis {

    // ------------------------------------------------
    // Mapper Class
    // ------------------------------------------------

    public static class LogMapper
            extends Mapper<Object, Text, Text, IntWritable> {

        private final static IntWritable one = new IntWritable(1);

        private Text error = new Text("ERROR");

        public void map(
                Object key,
                Text value,
                Context context
        ) throws IOException, InterruptedException {

            String line = value.toString();

            if (line.contains("ERROR")) {

                context.write(error, one);
            }
        }
    }

    // ------------------------------------------------
    // Reducer Class
    // ------------------------------------------------

    public static class LogReducer
            extends Reducer<Text, IntWritable, Text, IntWritable> {

        private IntWritable result = new IntWritable();

        public void reduce(
                Text key,
                Iterable<IntWritable> values,
                Context context
        ) throws IOException, InterruptedException {

            int sum = 0;

            for (IntWritable val : values) {

                sum += val.get();
            }

            result.set(sum);

            context.write(key, result);
        }
    }

    // ------------------------------------------------
    // Main Function
    // ------------------------------------------------

    public static void main(String[] args)
            throws Exception {

        Configuration conf = new Configuration();

        Job job = Job.getInstance(conf, "log analysis");

        job.setJarByClass(LogAnalysis.class);

        job.setMapperClass(LogMapper.class);

        job.setCombinerClass(LogReducer.class);

        job.setReducerClass(LogReducer.class);

        job.setOutputKeyClass(Text.class);

        job.setOutputValueClass(IntWritable.class);

        FileInputFormat.addInputPath(
                job,
                new Path(args[0])
        );

        FileOutputFormat.setOutputPath(
                job,
                new Path(args[1])
        );

        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
