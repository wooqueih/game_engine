#version 330
struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_diffuse2;
    sampler2D texture_diffuse3;
    sampler2D texture_diffuse4;
    sampler2D texture_diffuse5;
    sampler2D texture_diffuse6;
    sampler2D texture_diffuse7;
    sampler2D texture_diffuse8;
    sampler2D texture_specular1;
    sampler2D texture_specular2;
    sampler2D texture_specular3;
    sampler2D texture_specular4;
    sampler2D texture_specular5;
    sampler2D texture_specular6;
    sampler2D texture_specular7;
    sampler2D texture_specular8;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

void main() {
    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 1.0f);//material.shininess);

    vec4 ambient  = vec4(light.ambient, 1.0f) * normalize(texture(material.texture_diffuse1, TexCoords)
        + texture(material.texture_diffuse2, TexCoords)
        + texture(material.texture_diffuse3, TexCoords)
        + texture(material.texture_diffuse4, TexCoords)
        + texture(material.texture_diffuse5, TexCoords)
        + texture(material.texture_diffuse6, TexCoords)
        + texture(material.texture_diffuse7, TexCoords)
        + texture(material.texture_diffuse8, TexCoords));
    vec4 diffuse  = vec4(light.diffuse, 1.0f) * diff * normalize(texture(material.texture_diffuse1, TexCoords)
        + texture(material.texture_diffuse2, TexCoords)
        + texture(material.texture_diffuse3, TexCoords)
        + texture(material.texture_diffuse4, TexCoords)
        + texture(material.texture_diffuse5, TexCoords)
        + texture(material.texture_diffuse6, TexCoords)
        + texture(material.texture_diffuse7, TexCoords)
        + texture(material.texture_diffuse8, TexCoords));
    vec4 specular = vec4(light.specular, 1.0f) * spec * normalize(texture(material.texture_specular1, TexCoords)
        + texture(material.texture_specular2, TexCoords)
        + texture(material.texture_specular3, TexCoords)
        + texture(material.texture_specular4, TexCoords)
        + texture(material.texture_specular5, TexCoords)
        + texture(material.texture_specular6, TexCoords)
        + texture(material.texture_specular7, TexCoords)
        + texture(material.texture_specular8, TexCoords));
    vec4 result = ambient + diffuse + specular;
    FragColor = specular * diffuse * ambient;
}